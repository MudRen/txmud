// doctor.c
// 医者疗伤只是加速身体的恢复(eff_ 有效值的恢复),
// 不是一下子 call 满. 通过 heal_up 这个 condition
// 实现 '愈合'.

// 如果杀了 DOCTOR npc ，所有的医生很长时间(72 小时)都不会给此人疗伤、解毒。

// by Find.

#define PAY	2000	/* 医金20两银子 */

inherit NPC;
/* 一般的 doctor 也许多和药店老板之类的 npc 为同一物件，
 * 此处继承了 NPC ，会造成 DOCTOR 和 DEALER 不能合体，
 * 因此是否继承有待斟酌。
 */

nomask int is_doctor() {return 1;}
private void do_cure( object me, string what );

void init()
{
	::init();
	add_action("do_ask", "ask");
}

int do_ask( string arg )  /* return 0 let ask command process this action. */
{
	object me = this_player();
	string name, what;
	int f;

	if( me->is_busy() )
		return notify_fail(BUSY_MESSAGE);

	if( !arg || !stringp(arg) )
		return 0;

	if( sscanf( arg, "%s about %s", name, what ) != 2 )
		return 0; 

	if( !id(name) )
		return 0;

	if( what != "疗伤" && what != "解毒" )
		return 0;

	if( what == "疗伤"
	&& me->query("eff_kee") >= me->query("max_kee")
	&& me->query("eff_gin") >= me->query("max_gin")
	&& me->query("eff_sen") >= me->query("max_sen") )
	{
		write(sprintf("%s打量了你一下说道：这位%s面色红润，没有受伤呀。\n",
			name(),RANK_D->query_respect(me)));
		return 1;
	}

	if( what == "解毒" && !me->query_condition("snake_poison") )
	{
		write(sprintf("%s摇摇头说道：我只对蛇毒有点把握，其他的就无能为力了。\n",name()));
		return 1;
	}

	if(me->query("doctor/kill_doctor"))
	{
		if(time() - me->query("doctor/kill_doctor") <=0 )
		{
			write(sprintf("%s恶狠狠的看着你说道：“你这人穷凶极恶到对我们医生下毒手，我不会给你看病的！”\n",
				name()));
			return 1;
		}

		else
			me->delete("doctor/kill_doctor");
	}

	if( me->query("age") <= PROTECT_AGE ) /* 受保护年龄免费. */
	{
		write(sprintf("%s看了看你说道：“这么点的孩子就%s，真可怜，医金就免收了。”\n",
			name(),what == "疗伤"?"被伤成这样":"就中了毒"));
		do_cure(me, what);
		return 1;
	}

	if( me->query_condition("heal_up") )
	{
		write(name()+"说道：“你上次看病用的药还没有失效，不能再用药了，你过几天再来吧。”\n");
		return 1;
	}

	if( ! f = player_pay(me,PAY) || f == 2)
	{
		write(sprintf("%s皱着眉头说道：“没钱我就没办法了，先去拿%s吧。”\n",
			name(),chinese_value(PAY)));
		return 1;
	}

	do_cure(me, what);
	return 1;
}

private void do_cure( object me, string what )
{
	switch( what )
	{
		case "疗伤" :
			write(sprintf("%s端出一碗汤药给你喝了下去，然后说道：“好好休息，过两天就会好的。”\n",name()));
			me->apply_condition("heal_up", 20 );
			break;

		case "解毒" :
			/* 其他一般的毒完成后在这里加上，特殊的毒应该由本人的特制解药在区域中解决。*/

			write(name()+"端出一碗药给你喝下又看了看你说道：“好了，你体内的毒已经拔尽了。”\n");
			me->clear_condition("snake_poison");
			break;
        }
}