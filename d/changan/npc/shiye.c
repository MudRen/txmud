// shiye.c

inherit NPC;
 
void create()
{
	set_name("刘师爷", ({"shi ye"}));

	set("long", @LONG
他就是丞相府的刘师爷，据说深得丞相的信任，相
爷的奏章都是由他起草，丞相府里的大小事情他也
能做不少主。
LONG
);
	set("gender","男性");

        set("age",45);
        set("con",20);
        set("str",20);
	set("max_kee",900);
	set("max_gin",900);
	set("max_sen",900);

	set_skill("unarmed",60);
	set_skill("parry",100);
	set_skill("dodge",100);

        set("combat_exp",100000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
