// dizi.c

inherit NPC;

void create()
{
	set_name("���ŵ���", ({ "guard dizi" }) );

	if(random(10)<7)
		set("gender", "����" );
	else
		set("gender", "Ů��" );

	set("age", 20+random(15));
	set("class","huashan");

	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 70+random(100));

	set("long", "����һ����ɽ�ɵ�����ĵ��ӡ�\n");
	create_family("��ɽ��", 5, "����");

        set("combat_exp", 800000);

        set_skill("unarmed", 120);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        setup();

	if(random(10)<7)
		carry_object(WEAPON_DIR"sword")->wield();            
	carry_object(ARMOR_DIR"cloth")->wear();  
}
