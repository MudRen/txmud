//guardian.c ��֥��ڵ�����
inherit NPC;
void create()
{
        set_name("�ر�", ({"zang bing", "bing"}));
        set("long", "����һλ�뺷�Ĳ���С���ӣ��������ݵĿ������ܡ�\n");
        set("gender","����");
        set("age",25);
        set("con",20);
        set("str",50);
        set("max_kee",2000);
        set("max_gin",700);
        set("max_sen",700);
        set("max_force",2500);
        set("force",2500);
        set("force_factor",30);

        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("unarmed",150);
        set_skill("force",150);
        set_skill("fork",150);
        set_skill("ganchan",150);
        set_skill("qiuyue-fork",150);
        set_skill("feilong-quan",150);
//        set_skill("mizong-xinfa",150);
 
        map_skill("dodge","ganchan");        
        map_skill("unarmed","feilong-quan");
        map_skill("fork","qiuyue-fork");
        map_skill("parry","qiuyue-fork");
//      map_skill("force","mizong-xinfa");        

        set("combat_exp",700000);

        setup();
        carry_object(__DIR__"obj/hunt-fork")->wield();
        carry_object(__DIR__"obj/teng-armor")->wear();
}
