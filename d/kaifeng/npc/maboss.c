
#include <ansi.h>

inherit RIDE_SELLER;

void create()
{
        set_name("���ϰ�", ({"ma laoban","ma","laoban"}));
        set("long", @TEXT
���ϰ���������,���ľ�����.
TEXT
        );
        set("gender","����");
        set("age",41);
        set("combat_exp",1000);
        set("vendor_goods", ([
                RIDE_DIR"zouluo" : 7,
                RIDE_DIR"huangbiao" : 7,
                RIDE_DIR"zaohong_ma" : 7,
                RIDE_DIR"mg_horse" : 5,
                RIDE_DIR"yili_horse" : 4,
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
        if( !ob
        || (environment(ob) != environment())
        || file_name(environment()) != this_object()->query("startroom"))
                return;

        if(!userp(ob) && ob->query("is_beggar"))
        {
                message_vision(CYN"$N����$n��������⵰��������ʲô���Ͻ�����\n"NOR,this_object(),ob);
                ob->go_back_direction();
                return;
        }

        switch( random(2) )
        {
                case 0:
                        say( CYN"���ϰ�Ц�����˵������λ�͹�ѡһƥ����ɡ�\n"NOR);
                        break;
                case 1:
                        say( CYN"���ϰ��ͷ����˵������λ" + RANK_D->query_respect(ob)
                        + "�����������½��ļ�ƥ���\n"NOR);
                        break;
        }
}
