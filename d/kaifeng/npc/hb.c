inherit NPC;

void create()
{
        set_name("����ʦ", ({ "hu biaoshi" , "biaoshi" , "hu" }) );
        set("gender", "����" );
        set("age", 37);
        set("long", "����ʦ���ھ��Ѿ��ܶ����ˡ�\n");

        set("combat_exp", 150000);
        set("str", 20);
        set("int", 30);
        set("force", 2000);
        set("max_force", 2000);
        set("force_factor", 10);

        set_skill("dodge",80);
        set_skill("parry",80);
        set_skill("unarmed",70);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}
