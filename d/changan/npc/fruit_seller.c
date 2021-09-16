// design by 发现号(find) . all right reserved.

// fruit_seller.c
#include <ansi.h>

inherit F_DEALER;

void steal_it();

void create()
{
	/* 白天是水果贩子 */
	set_name("水果贩子", ({ "fruit seller","seller" }) );
	set("title","京城商会");
	set("nickname",HIY"童叟无欺"NOR);
	set("long", "一个卖水果的小贩，正在起劲的向行人兜售水果。\n");

	/* 晚上是小偷 */
	set_night_name("飞贼",({ "thief",}));
	set("night_title","长安白捞会");
	set("night_nickname",HIB"三手大圣"NOR);
	set("night_long","一个贼眉鼠眼的家伙,不知在盯着你看什么。\n");

	/*
	 * 由于晚上不是商贩,设置这个标记,
	 * 在晚上屏蔽掉 list mai 这些命令
	 * 如果要在白天屏蔽掉 list mai 命令
	 * 就 set("no_sell_day",1);
	 */

	set("no_sell_night",1);

	set("chat_chance", 5); /*随机动作的概率*/

	/* 白天的随机动作：吆喝 */
	set("chat_msg",({
		CYN"水果贩子说道：“买点水果吧，绝对新鲜。”\n"NOR,
		CYN"水果贩子说道：“公平交易，童叟无欺。”\n"NOR,
		}));

	/* 晚上的随机动作：偷同房间玩家身上的东西 */
	set("night_chat_msg",({
		"飞贼瞟了你一眼，不知打什么主意。\n",
		(: steal_it :),
		}));

	set("gender", "男性" );
	set("age", 28);

	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 100);
	set_skill("throwing", 30);

	set("vendor_goods", ([
		__DIR__"obj/apple":5,
		__DIR__"obj/pear":5,
		__DIR__"obj/strawberry":5,
		__DIR__"obj/grape":5,
		__DIR__"obj/melon":5,
	]) );

	setup();
	add_money("silver", 1);
	add_money("coin", 100);
	carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	/* 晚上是小偷，不吆喝。*/
	if( !is_day()) return;
        switch( random(2) ) {
                case 0:
                        say( "水果贩子高喊：买水果啦，又香又甜的水果。\n");
                        break;
                case 1:
                        say( "水果贩子高喊：又解渴又充饥啦。\n");
                        break;
        }
}

void steal_it()
{
	object *inv;
	int i;

	inv = all_inventory(environment());
	for(i=0;i<sizeof(inv);i++)
	{
		if(!userp(inv[i]))
			continue;
		if(is_busy())
			continue;
		command("steal all from "+inv[i]->query("id"));
		break;
	}
}