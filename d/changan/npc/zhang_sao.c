// zhang_sao.c

#include <ansi.h>

inherit NPC;

#define CLOTH_FEE	400000	/* �����·��ļ۸�ԼΪ 40 gold */

mapping clothes = ([
	"t_chougua" : ([
		"name" : HIC"�Ż����"NOR,
		"value": 250000,]),
	"b_chougua" : ([
		"name" : HIB"�������"NOR,
		"value": 220000,]),
	"s_skirt"   : ([
		"name" : WHT"�ػ���ȹ"NOR,
		"value": 250000,]),
	"l_skirt"   : ([
		"name" : HIG"����ȹ"NOR,
		"value": 300000,]),
]);

void create()
{
        set_name("�Ŵ�ɩ", ({ "boss zhang","zhang","boss" }) );
	set("title","�ļ��÷��� �ϰ�");
        set("gender", "Ů��" );
        set("age", 45);
        set("long","����һλ��ʮ��������긾Ů��ͷ�������⣬ϸƤ���⣬
�Լ������÷ǳ��á�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        setup();
	carry_object(__DIR__"obj/hua_skirt")->wear();
}

void init()
{
        object ob;

	add_action("do_list","list");
	add_action("do_buy",({ "mai","buy" }));
	add_action("do_ding","ding");

        if( living(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	string day_night;
	int time;

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N����$n�������ⲻ�������ĵط����Ͻ�����\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	if(!is_day())
	{
		sscanf( day_night(),"%s %d",day_night,time);
		say( (time > 480) ? CYN"�������Ѿ������ˣ�"+RANK_D->query_respect(ob)+
			"�����������ɡ�\n"NOR
			: ( (time <= 60) ? CYN"�Ŵ�ɩ��ȻһЦ�������Ͼ�Ҫ�����ˣ�������һ�°ɡ�\n"NOR
			: CYN"�Ŵ�ɩ˵�����ɵ껹û�п��ţ��������������ɡ�\n"NOR ) );
		return;
	}
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"�Ŵ�ɩ΢Ц��˵�����͹�Ҫ���·�������㿴����\n"NOR);
                        break;
                case 1:
                        say( CYN"�Ŵ�ɩ΢Ц��˵����û��������·���������Ҳ������������\n"NOR);
                        break;
		}
	}
}

int do_list(string arg)
{
	string *pattern;
	int i;

	if(!is_day())
	{
		command("say �͹�����������ɡ�\n");
		return 1;
	}

	pattern = keys(clothes);

	printf("Ŀǰ���۵ķ�װ�У�\n");
	for(i=0;i<sizeof(pattern);i++)
	{
		printf("%40-s��%s\n",
			clothes[pattern[i]]["name"]+"("+pattern[i]+")",
			chinese_value((int)clothes[pattern[i]]["value"]));
	}
	write("\n");
	return 1;
}

int do_buy(string arg)
{
	object ob,me = this_player();

	if(!is_day())
	{
		command("say �͹�����������ɡ�\n");
		return 1;
	}

	if(!arg || member_array(arg,keys(clothes)) == -1)
		return notify_fail("��Ҫ��ʲô��\n");

        switch (player_pay(me, clothes[arg]["value"]))
	{
		case 0:
			return notify_fail("�ɵ�ҲҪ����ѽ��û��Ǯ��ô�С�\n");
		case 2:
			return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		default:
			ob = new(ARMOR_DIR"cloth");
			ob->set("name",clothes[arg]["name"]);
			ob->move(me);
			write("�·�������������һ��"+((me->query("gender") == "����")?
				"Ӣ��":"Ư��")+"��\n");
			me->set("self_cloth",clothes[arg]["name"]);
			me->save();
			return 1;
	}
}

int do_ding(string arg)
{
	string help = "
������Ů��װÿ����"+chinese_value(CLOTH_FEE)+"��

 ding <��װ������>
��Ҫ������ʹ����ɫ�����������¿��Ʒ���
ע�⣺���Ʒ���ĸҪ��д��

$BLK$ - ��ɫ		$NOR$ - �ָ�������ɫ
$RED$ - ��ɫ		$HIR$ - ����ɫ
$GRN$ - ��ɫ		$HIG$ - ����ɫ
$YEL$ - ����ɫ		$HIY$ - ��ɫ
$BLU$ - ����ɫ		$HIB$ - ��ɫ
$MAG$ - ǳ��ɫ		$HIM$ - �ۺ�ɫ
$CYN$ - ����ɫ		$HIC$ - ����ɫ
$WHT$ - ǳ��ɫ		$HIW$ - ��ɫ

";
	object ob, me = this_player();

	if(!stringp(arg) || arg == "")
		return notify_fail(help);

	// "��ʦ�ļ���" ����ʦ��װ�����ơ�
	if(strsrch(arg,"��ʦ�ļ���") != -1)
		return notify_fail("�����·����ɽ�ʥ�С����������ˡ�\n");

        switch (player_pay(me, CLOTH_FEE))
	{
		case 0:
			return notify_fail("�ɵ�ҲҪ����ѽ��û��Ǯ��ô�С�\n");
		case 2:
			return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		default:
			arg = replace_string(arg, "$BLK$", BLK);
			arg = replace_string(arg, "$RED$", RED);
			arg = replace_string(arg, "$GRN$", GRN);
			arg = replace_string(arg, "$YEL$", YEL);
			arg = replace_string(arg, "$BLU$", BLU);
			arg = replace_string(arg, "$MAG$", MAG);
			arg = replace_string(arg, "$CYN$", CYN);
			arg = replace_string(arg, "$WHT$", WHT);
			arg = replace_string(arg, "$HIR$", HIR);
			arg = replace_string(arg, "$HIG$", HIG);
			arg = replace_string(arg, "$HIY$", HIY);
			arg = replace_string(arg, "$HIB$", HIB);
			arg = replace_string(arg, "$HIM$", HIM);
			arg = replace_string(arg, "$HIC$", HIC);
			arg = replace_string(arg, "$HIW$", HIW);
			arg = replace_string(arg, "$NOR$", NOR);
			arg += NOR;

			ob = new(ARMOR_DIR"cloth");
			ob->set("name",arg);
			ob->move(me);
			me->set("self_cloth",arg);
			me->save();
			write("�·������ˣ������Կ����ⲻ���⡣\n");
			return 1;
	}
}