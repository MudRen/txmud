// thief.c
inherit NPC;
 
void create()
{
        set_name("��������", ({ "oldman" }) );
        set("rank", "����");
        set("gender", "����" );
        set("age", 65);
        set("int", 25);
        set("con", 28);
        set("long", @LONG
һ�������µ����ˣ���Ȼ��ͺܴ��ˣ�ȴ��ɫ�����۾���������
LONG
);
        set("combat_exp", 3000);
        set("attitude", "heroism");
        set("env/wimpy", 70);
        set_skill("sword", 140);
        set_skill("parry", 150);
        set_skill("dodge", 200);
        set_skill("dagger", 125);
        set_skill("stealing",135); 
        setup();
 
        add_money("gold",1);
        //carry_object("/u/cloud/obj/cloth/black_cloth")->wear();
        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(WEAPON_DIR"sword")->wield();
        
        set("score",-30);
}
