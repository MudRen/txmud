// fenggai.c

inherit NPC;
inherit TEACH_NPC;

void create()
{
        set_name("���", ({"feng gai"}));
        set("long","����������ھ�����ε������ܹܣ���
���ڽ�����С�������ˡ�\n");
        set("title","�����ھ�--�ܹ�");
        set("gender","����");
	set(NO_KILL, 1);
        set("age",25);
        set("force",2500);
        set("max_force",2500);
        set("force_factor",50);

	set("max_kee",1200);
	set("max_gin",1200);
	set("max_sen",1200);

        set("combat_exp",400000);
	set("attitude", "friendly");

        set_skill("dodge",120);
	set_skill("parry",120);
        set_skill("unarmed",200);
        set_skill("force",200);
	set_skill("sword",90);
	set_skill("spells",260);
	set_skill("magic",260);

	set_valid_skill( ({ "spells","magic","unarmed" }) );

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(WEAPON_DIR"sword")->wield();
}

int is_apprentice_of(object ob)
{ return 1; }
