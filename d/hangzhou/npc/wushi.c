// wushi.c

inherit NPC;
 
void create()
{
        set_name("��ʿ", ({"wu shi"}));
        set("long", "����һλ��׳�����ߡ�\n");
        set("gender","����");

        set("age",35);
        set("con",30);
        set("str",30);
	set("kar",30);
	set("max_kee",900);
	set("max_gin",1200);
	set("max_sen",1200);
	set("max_force",1000);
	set("force",1000);
	set("force_factor",20);

	set_skill("unarmed",70);
	set_skill("stick",70);
	set_skill("parry",90);
	set_skill("dodge",90);
	set_skill("force",200);

	set("combat_exp",200000);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"stick")->wield();
}
