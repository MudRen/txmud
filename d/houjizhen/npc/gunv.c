// gunu.c 
// dicky.c


#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("��Ů", ({ "gu nv", "girl"}));
	set("nickname", HIG"���Ĺ�Ů"NOR);
	set("long", 
"��Ů��ִ�����ڿ�ջ�⣬�۾������Ķ��ſ�ջ�������ڳԺȵ���Ⱥ��\n"
"ÿ���˶������Լ�������ڱ��˿��������˷�ʱ�䣬��ȴ���ú���Ҫ��\n");
	set("gender", "Ů��");
	set("age", 28);
	set("title", HIB"�����Ź�"NOR);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);	
        set("per", 21);

        set("combat_exp", 800000);
        set("max_kee",2000);
        set("max_gin",2000);
        set("max_sen",2000);

        set("force", 4500);
        set("max_force", 4500);
        set("atman", 2500);
        set("max_atman", 2500);
        set("mana", 2500);
        set("max_mana", 2500);
        set("force_factor", 150);

        set_skill("jinghai-force",110);
        set_skill("longjiao-blade",100);
        set_skill("blade",120);
        set_skill("unarmed",120);                     
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("force",120);
        set_skill("sword",120);
        set_skill("bibo-sword",100);
        set_skill("perception",100);
        set_skill("xian-steps",120);
        set_skill("canhe-zhi",120);

        map_skill("unarmed","canhe-zhi");
        map_skill("force","jinghai-force");
        map_skill("dodge","xian-steps");
        map_skill("parry","bibo-sword");
        map_skill("sword","bibo-sword");

	set("chat_chance", 1);
	set("chat_msg", ({
		"��Ů�޺޵�˵��:Ϊ����ȴ�ٰ�Ī��ĳ�Թ������Ը�������һ���ӡ�\n",
	}) );
	set("inquiry", ([
		"����" : "ɱһ����Ҫ����ô�����㰮��һ���ˣ��������������\n",
		"�ܾ�" : "��С�ҾͶ��ñ����Լ�����֪��Ҫ�벻���˾ܾ�����õİ취�����Ⱦܾ����ˡ�\n",
		"����" : "����������˵�������㲻�ܹ���ӵ�е�ʱ����Ψһ�������ľ������Լ���Ҫ���ǡ�\n",
		"����" : "�����Ů���ǲ����ң������������Ѿ�����֪���������һ�����̲�ס���㣬��һ��Ҫƭ�ҡ�����������಻��Ը��Ҳ��Ҫ������������˲����ҡ�\n",
	]));

        setup();

        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(WEAPON_DIR"sword")->wield();
}


