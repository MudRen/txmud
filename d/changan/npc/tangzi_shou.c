// tangzi_shou.c

inherit NPC;
 
void create()
{
	set_name("������", ({"tangzi shou",}));
	set("long", "��λ�ǵ����ھֵ������֡�\n");
	set("gender","����");
	set("title","�����ھ�");

	set("chat_chance",5);
	set("chat_msg",({
	"�����ھ֣�����Զ����\n"
}));
	set("age",38);
	set("con",30);
	set("str",20);
	set("max_kee",700);
	set("max_gin",750);
	set("max_sen",750);

	set_skill("dodge",60);
	set_skill("parry",60);
	set_skill("unarmed",60);
	set_skill("blade",30);

	set("combat_exp",80000);

	setup();
	carry_object(WEAPON_DIR"blade")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();
}