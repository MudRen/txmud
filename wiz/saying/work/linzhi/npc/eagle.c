//eagle.c �ر�ŵ���֥��Ұ�ޣ����Կ��Ƿŵ�����

inherit NPC;

void create()
{
        set_name("��ӥ",({"black eagle","eagle","be"}));
        set("race", "Ұ��");
        set("age", 3);
        set("long","һͷĿ�⾼���Ĳ�ӥ��\n");
        
        set("str",45);
        set("con",50);
        set("kar",0);
        set("int",2);
        set("combat_exp",50000);
        set("max_sen",350);
        set("max_gin",350);
        set("max_kee",650);

        set("limbs",({"����","���","��צ","β��"}));
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 6);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
        "��ӥ������һ����ë��\n",
                "��ӥ��չһ�³���ư��Ŀ�����һ�ۡ�\n",}) );
                
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 30);

        setup();
}
