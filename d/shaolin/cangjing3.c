// Room: /d/shaolin/cangjing3.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

private mixed *msg_strs = ({

// 第一势
({
"两臂曲肘，徐徐平举至胸前成抱球势。",
"屈腕立掌，五指向上，掌心相对。",
"口中默念口诀：立身期正直，环拱手当胸，气定神皆剑，心澄貌亦恭。",
	}),

// 第二势
({
"足掌踏实，两膝微松，两手自胸前徐徐外展。",
"立掌，掌心向外，两目前视，内吸随动作慢慢游走。",
"口中默念口诀：足指挂地，两手平开，心平气静。"
	}),

// 第三势
({
"足尖着地，足跟提起；双手上举高过头顶。",
"两掌变拳，拳背向前，上肢用力将两拳缓缓收至腰部。",
"口中默念口诀：力周腿胁浑如植，咬紧牙关不放宽。舌可生津将腭舐，鼻能调息觉心安。",
	}),

// 第四势
({
"屈膝，提右脚跟，身向下沉，右虚步。",
"右手高举伸直，掌心向下，头微右斜，双目仰视右手心。",
"口中默念口诀：只手擎天掌覆头，更从掌内注双眸。鼻端吸气频调息，用力回收左右侔。",
	}),

// 第五势
({
"右手握拳，举至前上方，双目观拳。",
"左手握拳，左臂屈肘，斜垂于背后。",
"身体后转，成左弓步，左右手交替运行",
"口中默念口诀：两腿后伸前屈，小腹运气放松；用力在于两膀，观原须注双瞳。",
	}),

// 第六势
({
"两臂前平举，掌心向前，十指用力分开，虎口相对。",
"两眼怒目平视前方，随势脚跟提起。",
"口中默念口诀：挺身兼怒目，推手向当前；用力收回处，功须七次全。",
	}),

// 第七势
({
"脚尖相衔，足跟分离成八字形；两臂向前成叉掌立于胸前。",
"左手屈肘经下往后，成勾手置于身后，指尖向上。",
"口中默念口诀：侧首弯肱，抱顶及颈；自头收回，弗嫌力猛：左右相轮，身直气静。",
	}),

// 第八势
({
"左脚向左横跨一步，屈膝下蹲成马步。",
"上体挺直，两手叉腰，再屈肘翻掌向上，小臂平举如托重物状。",
"口中默念口诀：上腭坚撑舌，张眸意注牙；足开蹲似踞，手按猛如拿。",
	}),

// 第九势
({
"右手向左前方伸探，五指捏成勾手，上体左转。",
"腰部自左至右转动，右手亦随之自左至右水平划圈。",
"口中默念口诀：青龙探爪，左从右出；修士效之，掌气平实。",
	}),

// 第十势
({
"右脚向右跨一大步，屈右膝下蹲，成右弓左仆腿势。",
"上体前倾，双手撑地，头微抬起，目注前下方。",
"口中默念口诀：两足分蹲身似倾，屈伸左右腿相更；昂头胸作探前势，偃背腰还似砥平；",
	}),

// 第十一势
({
"双手仰掌缓缓向左右而上，用力合抱头后部，手指弹敲小脑后片刻。",
"直膝俯身弯腰，两手用力使头探于膝间作打躬状。",
"口中默念口诀：两手齐持脑，垂腰至膝间；头惟探胯下，口更齿牙关；",
	}),

// 第十二势
({
"两腿开立，双手仰掌由胸前徐徐上举至头顶，目视掌而移，身立正直。",
"十指交叉，旋腕反掌上托，掌以向上，身体上仰。",
"上体前屈，双臂下垂，推掌至地，昂首瞪目。",
"口中默念口诀：口注于心，息调于鼻；定静乃起，厥功维备。",
	}),
});

void create()
{
	set("short", "经室");
	set("long", @LONG
这是一间空荡荡的大房间，房间中央放着一张低矮的桌案，
桌案上点着两只大蜡烛。四周的墙壁上嵌着几块『石板』，石板
上刻着不少各种姿态的小人，边上还刻着一些字迹，中间一块石
板的上方赫然刻着“易筋经”三个大字，看来这里就是历代少林
前辈参悟 (canwu) 易筋经的地方。西面有一扇小木门，由于这里
是少林寺的要地，所以木门终年都是锁着的，如果你要出去可以
敲(knock)门叫人。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"cangjing2",
]));

	set(SAFE_ENV,1);
	setup();
	create_door("west", "木门", "east", DOOR_CLOSED,LOCKED,__DIR__"npc/obj/cangjing_key");
}

void init()
{
	add_action("do_knock",({ "knock","qiao" }));
	add_action("do_canwu","canwu");
}

int do_knock(string arg)
{
	object room,hc;

	if(arg != "door" && arg != "门" && arg != "木门")
		return notify_fail("你要敲什么？\n");

	message_vision("$N抬手在木门上轻轻敲了几下。\n",this_player());

	if(!room = find_object(__DIR__"cangjing2"))
		room = load_object(__DIR__"cangjing2");
	if(!room)
		return notify_fail("但是外面没有一点动静。\n");

	if(!objectp(hc = present("hui chi",room)))
		return notify_fail("但是外面没有一点动静。\n");

	hc->want_out();
	return 1;
}

int do_canwu(string arg)
{
	object me = this_player();
	mapping yjj;
	int qn;

	if(me->query("class") != "shaolin")
		return 0;

	if(arg != "石板")
		return notify_fail("你要参悟什么？\n");

	if(!me->query("family/can_study_yijin"))
		return notify_fail("由于你的武学基础不够，对于石板上的内容无法理解。\n");

	if(me->query("gin") < 250 || me->query("sen") < 250)
		return notify_fail("你现在精神太差，无法集中精力参悟高深的武学精要。\n");

	if(me->query("force") < 1200)
		return notify_fail("你现在内力不足无法运功。\n");

	me->start_busy(120);

	if(!mapp(yjj = me->query("family/yijin-jing")))
		yjj = (["level":0,"step":0]);

	if(yjj["level"] >= 12)
	{
		me->stop_busy();
		return notify_fail("你已经将『易筋经』参悟透彻、融会贯通了。\n");
	}

	if(yjj["level"] < 0)
		yjj["level"] = 0;

	qn = (yjj["level"] + 1)*(yjj["level"] + 1)*30;

	if( me->query("potential") - me->query("learned_points") < qn )
	{
		me->stop_busy();
		return notify_fail(sprintf("参悟『易筋经』第%s势的第%s重需要花费 %d 点潜能。\n",
			chinese_number(yjj["level"] + 1),chinese_number(yjj["step"] + 1),qn ));
	}

	me->receive_damage("gin",200,"tire");
	me->receive_damage("sen",200,"tire");
	me->add("force",-1000);
	me->add("learned_points",qn);

	call_out("do_begin",2,me,yjj);
	return 1;
}

private void do_begin(object me,mapping yjj)
{
	if(!objectp(me)
	|| !living(me)
	|| environment(me) != this_object()
	|| !mapp(yjj))
		return;

	// 起手势
	message_vision("\n$N头端平，目前视，口微闭，含胸调吸，气走全身，渐渐进入忘我之佳境。\n\n",me);
	call_out("do_lasting",8,me,yjj,0);
}

private void do_lasting(object me,mapping yjj,int n)
{
	string *msg;

	if(!objectp(me)
	|| !living(me)
	|| environment(me) != this_object()
	|| !mapp(yjj))
		return;

	if(yjj["level"] < 0 || yjj["level"] >= sizeof(msg_strs))
	{
		write("出现错误，请立刻向巫师报告。\n");
		me->stop_busy();
		return;
	}

	msg = msg_strs[yjj["level"]];
	if(!sizeof(msg) || n < 0 || n >= sizeof(msg))
	{
		write("出现错误，请立刻向巫师报告。\n");
		me->stop_busy();
		return;
	}

	message_vision(sprintf("\n$N%s\n\n",msg[n]),me);

	if( ++n >= sizeof(msg))
	{
		call_out("do_end",4,me,yjj);
		return;
	}

	call_out("do_lasting",8,me,yjj,n);
}

private void do_end(object me,mapping yjj)
{
	if(!objectp(me)
	|| !living(me)
	|| environment(me) != this_object()
	|| !mapp(yjj))
		return;

	if( ++yjj["step"] >= 3)
	{
		yjj["level"]++;
		yjj["step"] = 0;

		if(yjj["level"] >= 12)
			tell_object(me,BWHT HIG"\n你将『易筋经』完全参悟透彻、融会贯通了。\n\
你在武学方面的修为从此进入了一个全新的境界。\n\n"NOR);
		else
		tell_object(me,sprintf(HIY"\n你已经将『易筋经』的第%s势彻底领悟了，你的武学修为进入了一个新的境界。\n\n"NOR,
			chinese_number(yjj["level"]) ));
	}

	else
		tell_object(me,sprintf(HIY"\n通过对第%s重的参悟，你对『易筋经』的第%s势有了进一步的了解。\n\n"NOR,
			chinese_number(yjj["step"]),chinese_number(yjj["level"]+1) ));

	me->set("family/yijin-jing",yjj);
	tell_room(__FILE__,me->name()+"行功完毕，疲劳的垂下了双手。\n",({me}));
	me->stop_busy();
}
