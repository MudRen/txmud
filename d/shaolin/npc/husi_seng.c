// jjseng.c

inherit NPC;

void create()
{
	set_name("���¹�ɮ", ({ "husi seng", "seng" }) );

	set("class","shaolin");
	create_family("������", 39, "����");

	set("gender", "����" );
	set("age", 33);
	set("long", "����һλ��ĸߴ��ɮ�ˣ��Ӹ߸�¡��
��̫��Ѩ�Ͽ��ɼ���һλ�书���֡�\n");
	set("attitude", "peaceful");

	set("chat_chance", 10);
        set("chat_msg", ({
	(: random_move :),
}));

	set("combat_exp", 1500000);
	set("str", 67);
	set("kar",35);
	set("max_kee",1500);
	set("kee",1500);
	set("max_gin",1500);
	set("gin",1500);
	set("max_sen",1500);
	set("sen",1500);
	set("force", 2000);
	set("max_force", 2000);
	set("atman", 2000);
	set("max_atman", 2000);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force_factor", 60);

	set("chat_chance_combat",25);
	set("chat_msg_combat",({
		(: perform_action, "stick.xiangmo" :),
}));

	set_skill("unarmed",120);
	set_skill("dodge",150);
	set_skill("parry",150);
	set_skill("force",100);
	set_skill("stick",150);
	set_skill("weituo-gun",150);
	set_skill("iron-cloth",180);
	set_skill("perception",150);
	set_skill("yiqi-force",100);
	set_skill("ganchan",100);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");
	map_skill("parry","weituo-gun");
	map_skill("stick","weituo-gun");

	setup();

	carry_object(__DIR__"obj/tong_stick")->wield();
	carry_object(__DIR__"obj/seng_pao")->wear();
}
