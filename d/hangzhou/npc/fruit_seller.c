// fruit_seller.c

inherit F_DEALER;

void steal_it();

void create()
{
	set_name("���", ({ "huo ji" }) );
	set("title","ˮ����");

	set("long", "����һλˮ����Ļ�ơ�\n");

	set("sell_all_day",1);

	set("chat_chance", 5);
	set("chat_msg",({
		"ˮ������˵���������ˮ���ɣ��������ʡ���\n",
		}));

	set("gender", "����" );
	set("age", 28);

	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
	set_skill("dodge", 100);
	set_skill("throwing", 30);

	set("vendor_goods", ([
		__DIR__"obj/apple":10,
		__DIR__"obj/melon":10,
		__DIR__"obj/grape":10,
	]) );

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}
