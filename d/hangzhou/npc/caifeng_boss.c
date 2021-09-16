
// caifeng_boss.c

#include <ansi.h>

inherit NPC;

mapping clothes = ([
        "f_skirt" : ([
		"name" : HIC"���鳤ȹ"NOR,
                "value": 250000,]),
        "h_skirt" : ([
                "name" : HIW"����ɴȹ"NOR,
                "value": 220000,]),
        "l_pao"   : ([
                "name" : HIB"������"NOR,
                "value": 250000,]),
        "l_skirt"   : ([
                "name" : HIG"���̳�ȹ"NOR,
                "value": 300000,]),
]);

void create()
{
        set_name("�����", ({ "hua dajie","boss" }) );
        set("title","�÷����ϰ���");
        set("gender", "Ů��" );
        set("age", 35);
	set("per",25);
        set("long","����һλ����Ц������긾Ů��\n");
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
                        : ( (time <= 60) ? CYN"�������ȻһЦ�������Ͼ�Ҫ�����ˣ�������һ�°ɡ�\n"NOR
                        : CYN"�����˵����С�껹û�п��ţ��������������ɡ�\n"NOR ) );
                return;
        }
        else if( random(2) )
		say( CYN"�����΢Ц��˵�����͹�Ҫ���·�������㿴����\n"NOR);
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
                        return notify_fail("С��ҲҪ����ѽ��û��Ǯ��ô�С�\n");
                case 2:
                        return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
                default:
                        ob = new(ARMOR_DIR"cloth");
                        ob->set("name",clothes[arg]["name"]);
                        ob->move(me);
                        write("�·�������������һ��"+((me->query("gender") == "����")?
                                "�ѹ����Ƕ�����":"Ư��")+"��\n");
                        me->set("self_cloth",clothes[arg]["name"]);
                        me->save();
                        return 1;
        }
}
