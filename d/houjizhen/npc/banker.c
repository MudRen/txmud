// banker.c
// by dicky

inherit NPC;

void create()
{
        set_name("��һ��", ({ "long yimen","long","boss"}) );
        set("title", "Ǯׯ�ϰ�");
        set("gender", "����" );
        set("age", 29);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("long",
"��һ���Ǹ��������ǳ���Ĭ���ˣ���ʱ�����Щ
�Ĳ����ɵ����ӣ����ľ���Ի�������������
������Ī��ĸо����Ͼ���ǰ���Ǹ������ˣ�����
һ���������书��\n");
        set("combat_exp", 20000);
        set("attitude", "friendly");

	set("max_atman", 500);
	set("atman", 500);
	set("max_force", 2000);
	set("max_kee", 2000);
	set("max_sen", 2000);
	set("force", 2000);
	set("force_factor", 20);
	set("max_mana", 500);
	set("mana", 500);

	set_skill("sword", 100);
	set_skill("unarmed",100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	setup();
        
	carry_object(WEAPON_DIR"sword")->wield();
	carry_object(ARMOR_DIR"cloth")->wear();

        add_money("silver", 5);
}

int accept_fight(object me)
{
        command("say ����������˭�ĵ��̣���������Ұ����");
        command("heihei "+ me->query("id"));
        kill_ob(me);
        return 1;
}