// judge.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("宝官", ({ "judge" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "他脸上的表情仿佛是看到了你口袋里的钱一般。\n");
        set("per", 25);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);

        set("inquiry", ([
                "赌" : "客官您把钱给我就行了。\n",
        ]) );

        setup();
        add_money("silver", 1);
        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(WEAPON_DIR"dagger")->wield();
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
	|| file_name(environment()) != this_object()->query("startroom") )
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N冲着$n喊道：这不是穷光蛋来的地方，赶紧滚！\n"NOR,this_object(),ob);
		ob->go_back_direction();
		return;
	}

	if(!random(3))
		say( CYN"宝官喊道：“快来赌吧，赌全色可是一赔八！”\n"NOR);
}
