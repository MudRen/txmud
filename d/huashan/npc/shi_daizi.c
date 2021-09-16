// shi_daizi.c

inherit NPC;

void create()
{
	set_name("施戴子", ({ "shi daizi" }) );

	set("gender", "男性" );

	set("age", 35);
	set("class","huashan");

	set("max_force", 2000);
	set("force", 2000);

	set("long","这是一位看起来很稳重的华山弟子。\n");

	create_family("华山派", 4, "弟子"); 

	set("combat_exp", 800000);

	set_skill("unarmed", 120);
	set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);

	setup();
	carry_object(__DIR__"obj/hs_cloth")->wear();  
}
