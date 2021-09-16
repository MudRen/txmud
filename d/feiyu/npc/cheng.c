
#include <ansi.h>

inherit NPC;

int ask_me(object me);

void create()
{
        set_name("�̺�", ({ "cheng he"}) );
        set("gender", "����" );
        set("title",HIW"����������"NOR);
        set("age", 21);
        set("attitude", "peaceful");
        set("per",30);
        set("max_force",3000);
        set("force",3000);
        set("combat_exp",3000000);

        set_skill("sword",250);
        set_skill("force",250);
        set_skill("parry",250);
        set_skill("dodge",250);
        set_skill("literate",100);
        set_skill("unarmed",250);
        set_skill("jieqing-sword",250);
        set_skill("suiyu-force",250);
        set_skill("zuiyue-strike",250);
        set_skill("piaoyu-steps",250);

        map_skill("unarmed","zuiyue-strike");   
        map_skill("dodge","piaoyu-steps");      
        map_skill("parry","jieqing-sword");     
        map_skill("sword","jieqing-sword");     
        map_skill("force","suiyu-force");       

        set("inquiry", ([
                "����" : ("��������һ��Ҫ����Сٻ���õ����塣\n"),
                "��Сٻ" : (: ask_me :),
        ]) );
        set("long","�̺�������ŨŨ��üë��һͷƮ�ݵĳ�����\n");

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int ask_me(object me)
{
        command ("sigh");
        command ("say Сٻ���ö���ʵ����̫���ˣ����Ǹ�����²�����ǿ��
���ԣ���Ҳû�а취����Ҳ���뿴������ô���ܣ�������һֱ���������\n");
        return 1;
}


int accept_object(object me, object ob)
{
        object obj;

        if(ob->query("id") == "yu pei")
        {
                if (!me->query_temp("louth_shengji1_pei1"))
                {
                        command ("?");
                        command ("say ��ö�����Ǵ������ģ�\n");
                        return 1;
                }
        me->delete_temp("louth_shengji1_pei1");
        me->set_temp("louth_shengji1_pei2",1);
        command ("sigh");
        command ("say �벻����ô��ʱ��û�м���Сٻ���ã�������һֱ�����������¡�\n");
        command ("say ��Ҳ���Ұ��������彻��Сٻ���ðɣ���������Ҫ������ң������ںܺá�\n");
        return 1;
        }
        return 0;
}
