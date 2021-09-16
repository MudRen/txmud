// city_guard.c

inherit NPC;

void create()
{
	set_name("城门官", ({ "city guard", "guard" }) );
        set("long",@LONG
这是一位守卫长安城门的城门官，不时
的还盘查过往的行人，一付一丝不苟的
样子。
LONG
);

	set_night_name("守城卫兵", ({ "city guard", "guard" }) );
        set("night_long",@LONG
这是一位守城卫兵静静的站在这里，一
双炯炯有神的眼睛不时的扫视着昏暗的
街道。
LONG
);
	set("attitude", "peaceful");
	set("vendetta_mark", "guanfu");

        set("str", 40);
        set("cor", 26);
	set("con", 40);
	set("max_kee",2000);
	set("max_gin",2000);
	set("max_sen",2000);
	set("max_force",2000);
	set("force",2000);
	set("force_factor",30);

        set("combat_exp", 400000);

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "守城卫兵喝道：还不快放下武器束手就缚？\n",
                "守城卫兵喝道：大胆刁民！竟敢杀官造反？\n"
        }) );

	set_skill("unarmed", 70);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);

	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 30);

        setup();

	carry_object(ARMOR_DIR"armor")->wear();
	carry_object(WEAPON_DIR"sword")->wield();
}
