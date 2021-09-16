// yu.c
// by dicky

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit __DIR__"gb_sd.c";

void create()
{
        set_name("�����", ({"yu duozhu", "duozhu"}));
        set("title", "ؤ��˴�����");
        create_family("ؤ��", 5, "�˴�����");

        set("gender", "����");
        set("age", 55);
        set("long","����ؤ��˴�����,�ƹܳ����ֶ档\n");
        set("attitude", "peaceful");
        set("no_get", "������������̫���ˡ�\n");
        set("str", 35);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("apprentice",1);
        set("kee", 2400);
        set("max_kee", 2400);
        set("gin", 2400);
        set("max_gin", 2400);
        set("force", 2400);
        set("max_force", 2400);
        set("atman", 1000);
        set("max_atman", 1000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 50);
        set("combat_exp", 2500000);
        
        set_skill("force", 150);
        set_skill("gaibang-force", 150);  // ؤ����
        set_skill("dodge", 150);
        set_skill("wanli-steps", 150);    // �������
        set_skill("parry", 150);
        set_skill("literate", 100); 
        set_skill("blade", 150);
        set_skill("qimen-blade",150);     // ���ŵ���
        set_skill("begging", 100);
        set_skill("lianhua-zhang",150);     // ������
        set_skill("unarmed",150);

        map_skill("blade","qimen-blade");       
        map_skill("force", "gaibang-force");
        map_skill("dodge", "wanli-steps");
        map_skill("parry","qimen-blade");
        map_skill("unarmed","lianhua-zhang");

        set("inquiry", ([
                "ؤ��" : "����ؤ�������µ�һ��\n",
              ]));
        setup();

        carry_object(__DIR__"obj/bainayi")->wear();
        carry_object(__DIR__"obj/gb_budai8")->wear();
        carry_object(WEAPON_DIR"blade")->wield();
}

void attempt_apprentice(object ob)
{
	gb_apprentice(ob);        
}

#include "zhuanhua.h";