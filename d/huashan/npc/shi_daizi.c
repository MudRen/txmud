// shi_daizi.c

inherit NPC;

void create()
{
	set_name("ʩ����", ({ "shi daizi" }) );

	set("gender", "����" );

	set("age", 35);
	set("class","huashan");

	set("max_force", 2000);
	set("force", 2000);

	set("long","����һλ�����������صĻ�ɽ���ӡ�\n");

	create_family("��ɽ��", 4, "����"); 

	set("combat_exp", 800000);

	set_skill("unarmed", 120);
	set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);

	setup();
	carry_object(__DIR__"obj/hs_cloth")->wear();  
}
