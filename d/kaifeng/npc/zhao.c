inherit NPC;

void create()
{
        set_name("����ү��", ({ "zhao lao" , "zhao"}) );
        set("gender", "����" );
        set("age", 65);
        set("long", "��������ү�ӵ���......\n");

        set("combat_exp", 20000);
        set("attitude", "heroism");

	set("max_kee",800);
	set("max_gin",800);
	set("max_sen",800);
        set_skill("unarmed", 30);
        set_skill("parry", 50);
        set_skill("dodge", 50);

        setup();
        add_money("silver", 1);
        carry_object(ARMOR_DIR"cloth")->wear();        
}
