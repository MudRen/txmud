// banker.c

inherit NPC;
void create()
{
        set_name("³�ò�", ({ "lu decai","lu"}) );
        set("title", "Ǯׯ�ϰ�");
        set("gender", "����" );
        set("age", 46);

        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("long",@LONG
³�ò��Ǹ��������൱˹�ĵ��ˣ�Ц����
һ��������������ʱĿ��һ�����۾����
¶��һ˿��а�����⡣
LONG
);

	set("combat_exp", 2000);
	set("attitude", "friendly");

	set("max_atman", 500);
	set("atman", 500);
	set("max_force", 1000);
	set("force", 1000);
	set("force_factor", 20);
	set("max_mana", 500);
	set("mana", 500);

	set_skill("unarmed",100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	setup();
        
	carry_object(ARMOR_DIR"cloth")->wear();
}

int accept_fight(object me)
{
        command("say ��... Ҫ������ɣ����ǽ�����û��˼��");
        command("grin");
        kill_ob(me);
        return 1;
}
