// xianling.c

inherit NPC;
 
void create()
{
	set_name("԰����", ({"yuan jinbao", "yuan", "xianling"}));
	set("title","��������");

	set("long", @LONG
�����ǳ����ǵ��������������������������
�٣����ڳ����Ǿ�ʦ����ͷ�߹����ƣ������⸷
��Ա�������ڣ���԰������֪��ʲô�ֶ�����ͨ
�ڣ�����ó�Ұ���µĺ�����
LONG
);

	set("gender","����");
	set("vendetta_mark", "guanfu");
	set("attitude","peaceful");

        set("age",45);

	set("max_kee",2000);
	set("max_gin",2000);
	set("max_sen",2000);

	set_skill("unarmed",150);
	set_skill("dodge",150);
	set_skill("parry",150);

        set("combat_exp",600000+random(200000));

        setup();
        carry_object(__DIR__"obj/guanfu")->wear();
}
