#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("�ձ��ϴ���", ({ "lao daniang","daniang"}) );
        set("gender", "Ů��" );
        set("age", 61);
        set("long","�ձ��ϴ������������ơ�\n");
        set("combat_exp", 10);
        set("attitude", "friendly");
        set("vendor_goods", ([
                FOOD_DIR"chicken_leg" : -1,
                __DIR__"obj/huashengmi" : -1,
                FOOD_DIR"dumpling" : -1,
               LIQUID_DIR"wineskin" : -1,
        ]) );
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
 
void init()
{
        object ob;
 
        ::init();
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

        if(!is_day())
        {
                sscanf( day_night(),"%s %d",day_night,time);
                say( (time > 480) ? CYN"С���Ѿ������ˣ�"+RANK_D->query_respect(ob)+
                        "���������ɡ�\n"NOR
                        : ( (time <= 60) ? CYN"�ձ��ϴ������һ��Ϳ����ˣ���λ�͹����һ�°ɡ�\n"NOR
                        : CYN"�ձ��ϴ����������۾�˵�����컹û�����������ڲ�Ӫҵ��\n"NOR ) );
                return;
        }
        else
        {
                switch( random(2) )
                {
                case 0:
                        say( CYN"�ձ��ϴ���Ц�Ǻ�˵������λ" + RANK_D->query_respect(ob)
                                + "����룬�ȵ�ƣ�������ը�����Ļ����ף�\n"NOR);
                        break;
                case 1:
                        say( CYN"�ձ��ϴ���˵������λ" + RANK_D->query_respect(ob)
                                + "�������Ъһ�ᡣ\n"NOR);
                        break;
                }
        }
}
