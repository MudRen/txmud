// oldwoman.c ��֥������ϴ���
inherit NPC;
void create()
{
        set_name("�������", ({ "old woman", "woman" }) );
        set("gender", "Ů��" );
        set("age", 63);
        set("long", "һ������ɫ˥���ϴ����������������ġ�\n");
        set("combat_exp", 1500);
        set("env/wimpy", 80);
        set("str", 13);
        set("attitude", "friendly");
        set("inquiry", ([
                "��" : "������ĸ����...һ�����Ǽ���������ҵ��С��å�ɵġ�",
                "��å" : "�Ǽ���С��å���첻����ҵ������С��ͬ��Ⱦƶ�Ǯ��"
        ]) );
        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
                "����������ĵ�˵�����Ǹ���ɱ�ģ�͵���ҵ���ĸ����\n",
                "�������̾�˿�����˵�������Ǹ�ʲ����������\n",
                "���������������ż�������������ˡ�\n",
        }) );
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("coin", 100);
}
