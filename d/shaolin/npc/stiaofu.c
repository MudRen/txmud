// stiaofu.c

inherit NPC;

void create()
{
	set_name("ɽ����", ({ "tiao fu", "porter" }) );
	set("gender", "����" );
	set("age", 20+random(15));
	set("long","���Ǹ���ʵ�ͽ��������򣬿���������
������ɽ�����ȼ���ǳ����\n");
	set("combat_exp", 10000+random(5000));

	set_skill("dodge",60);
	set_skill("unarmed",40);

	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}