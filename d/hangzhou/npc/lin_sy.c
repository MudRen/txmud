// lin_sy.c

inherit NPC;
 
void create()
{
	object ob;

        set_name("�ָ���", ({"lin funan"}));
	set("title","�ּ���ү");

	set("long", "��λ���Ǻ����ּҵĴ���ү��ƽʱ�������
�޶���������Ϊ������ǮƸ���˲�������
���Ҳѧ��һ������书������Ҳû��
���ǡ�\n");
	set("gender","����");

        set("age",28);
        set("con",30);
        set("str",30);
	set("kar",30);

	set("max_kee",1200);
	set("max_gin",2000);
	set("max_sen",2000);
	set("max_force",1500);
	set("force",1500);
	set("force_factor",20);

	set_skill("unarmed",150);
	set_skill("sword",100);
	set_skill("parry",120);
	set_skill("dodge",120);
	set_skill("force",200);
	set_skill("lianhuan-sword",80);

	map_skill("sword","lianhuan-sword");
	map_skill("parry","lianhuan-sword");

	set("combat_exp",250000);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
	ob = carry_object(__DIR__"obj/liuxing_sword.c");
	if(ob)
		ob->wield();
}
