// stdnpc_6.c

inherit STD_NPC;
 
void create()
{
	set_name("������", ({ "mengmian ren","ren","mengmian"}) );
	set("long", "����һλĪ������ļһ�,�������,��������������Ŀ��\n");
	set("gender","����");

	set("age",32);

	set_npc_level(10);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}
