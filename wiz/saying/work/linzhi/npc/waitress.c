//waitress.c ��֥���¥���д���
#include <ansi.h>
inherit F_DEALER;
void create()
{
        set_name("Ů�д�", ({"xiao jie","waitress",}));
        set("title","�������");
        set("gender", "Ů��" );
        set("age",18);
        set("per",27);
        set("long","һλ�����С�㣬����ȥ�������ˡ�\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods", ([
                "/d/changan/npc/obj/noodles" : -1,
                "/d/changan/npc/obj/ysd" : -1,
                FOOD_DIR"chicken_leg" : -1,
                LIQUID_DIR"bowl" : -1,
                MISC_DIR"top" : 50,
        ]) );
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
}
void init()
{
        object ob;
        ::init();
        if( living(ob = previous_object()) && !is_fighting() && !wizardp(ob))
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
                message_vision(CYN"$N�û�˵�����۾�����$n,��Ǹ��һЦ��\n"NOR,this_object(),ob);
                ob->go_back_direction();
        }

        if(!is_day())
        {
                sscanf( day_night(),"%s %d",day_night,time);
                say( (time > 480) ? CYN"��ô����죬�����Ѿ������ˣ�"+RANK_D->query_respect(ob)+
                        "�����������ɡ�\n"NOR
                        : ( (time <= 60) ? CYN"Ů�д�ǸȻһЦ�����Ͼ�Ҫ�����ˣ���λ�͹����һ�°ɡ�\n"NOR
                        : CYN"Ů�д�ǿ����˵����С�껹û�п��ţ��������������ɡ�\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"Ů�д�Ц�����˵������������ķ���Զ��������\n"NOR);
                        break;
                case 1:
                        say( CYN"Ů�д���һ��˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n"NOR);
                        break;
                }
        }
}
