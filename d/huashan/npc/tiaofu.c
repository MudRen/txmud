//tiaoshan.c

inherit NPC;

void create()
{
	set_name("����", ({ "tiao fu" }) );

	set("gender", "����" );

	set("age", 26);
	set("long", "һ����׳�Ĵ󺺣����ϴ����ֲ��·���
���ϵ���һ�����\n");

	set("combat_exp", 2000);
	set("str", 30);
	set("chat_chance", 3);

	set("chat_msg", ({
		"���������������ѽ...����һ��Ҳ�Բ������ٱ�����\n",
		"�Է�̾�������������²�̫ƽ������ɽ����Ҳ������ࡣ\n",
		(: random_move :),
}) );
	set("env/wimpy", 10);

	set("inquiry", ([
		"��ɽ":"��ɽ������Χ�����ﶼ�ǻ�ɽ��",
		"��ɽ��" : "�����Ұɣ���Զ�ˡ�",
		"������":"������������˵���������������������ܼ��ĵ����أ�",
		"here": "������ǻ�ɽ��",
]) );

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}
