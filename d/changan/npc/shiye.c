// shiye.c

inherit NPC;
 
void create()
{
	set_name("��ʦү", ({"shi ye"}));

	set("long", @LONG
������ة�ฮ����ʦү����˵���ة������Σ���
ү�����¶���������ݣ�ة�ฮ��Ĵ�С������Ҳ
������������
LONG
);
	set("gender","����");

        set("age",45);
        set("con",20);
        set("str",20);
	set("max_kee",900);
	set("max_gin",900);
	set("max_sen",900);

	set_skill("unarmed",60);
	set_skill("parry",100);
	set_skill("dodge",100);

        set("combat_exp",100000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
