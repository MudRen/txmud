// strongman.c
inherit NPC;
void create()
{
        set_name("路人", ({ "lu ren" }) );
        set("gender", "男性" );
        set("age", 37);
        set("combat_exp", 2000);
        set("long", "    一个普通的过路人，像这样的人一天可以在路上碰见几十个。\n");
        setup();
        add_money("silver", 2);
        carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}
