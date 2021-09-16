// shusheng.c

inherit NPC;
 
void create()
{
        set_name("书生", ({"shu sheng"}));
        set("long", "这是一位眉清目秀的书生。\n");
        set("gender","男性");

        set("age",35);
        set("con",30);
        set("str",20);
	set("kar",30);

	set("max_kee",900);
	set("max_mana",1200);
	set("max_atman",1200);
	set("max_force",1000);
	set("force",1000);
	set("force_factor",10);

	set_skill("unarmed",40);
	set_skill("parry",70);
	set_skill("dodge",70);

	set("combat_exp",20000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
	if(!random(4))
		carry_object(BOOK_DIR"lian_book");
}
