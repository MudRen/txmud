
#include <ansi.h>

inherit RIDE_SELLER;

void create()
{
        set_name("马老板", ({"ma laoban","ma","laoban"}));
        set("long", @TEXT
马老板人如其名,长的就像马.
TEXT
        );
        set("gender","男性");
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
                message_vision(CYN"$N冲着$n喊道：穷光蛋跑着来做什么！赶紧滚！\n"NOR,this_object(),ob);
                ob->go_back_direction();
                return;
        }

        switch( random(2) )
        {
                case 0:
                        say( CYN"马老板笑咪咪地说道：这位客官选一匹坐骑吧。\n"NOR);
                        break;
                case 1:
                        say( CYN"马老板点头哈腰说道：这位" + RANK_D->query_respect(ob)
                        + "来看看咱们新进的几匹坐骑。\n"NOR);
                        break;
        }
}
