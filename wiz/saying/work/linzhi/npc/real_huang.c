//real_huang.c ��֥������Ǯׯ�ϰ塣
#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
        set_name("������", ({ "huang shengfa","huang"}) );
        set("title", "Ǯׯ�ϰ�");
        set("gender", "��" );
        set("age", 35);
        set("str", 73);
        set("cor", 40);
        set("cps", 30);
        set("int", 36);
        set("per", 19);
        set("con", 24);
        set("spi", 30);
        set("kar", 15);

        set("long",
"��������������¡�������ϰ壬ʵ���ϳ����Ǹ�
ֻ��������ѡ�\n");

        set("combat_exp", 2000000);
        set("attitude", "killer");

        set("max_atman", 700);
        set("atman", 700);
        set("max_force", 4000);
        set("force", 8000);
        set("force_factor", 100);
        set("max_mana", 600);
        set("mana", 600);

        set_skill("blade", 200);
        set_skill("unarmed",200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
//        set_skill("fire-blade", 200);
//        set_skill("dashouyin", 200);
//        set_skill("jimie-steps", 200);
//        set_skill("mizong-xinfa", 200);
//        map_skills("blade","fire-blade");
//        map_skills("unarmed","dashouyin");
//        map_skills("parry","fire-blade");
//        map_skills("dodge","jimie-steps");
//        map_skills("force","mizong-xinfa");
        
        setup();
        carry_object(WEAPON_DIR"blade")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}
void unconcious()
{
        object winner=query_temp("last_damage_from");
        object ob=this_object();
        winner->set_temp("mark/killed_huang",1);
        if ((int)winner->query_temp("mark/���ϰ�"))
        {
                winner->remove_all_enemy();
                ob->remove_all_enemy();
                winner->set_temp("mark/���ϰ�",1);
                say(HIC"��������̾һ������Ȼ������\n"NOR);
                say(CYN"������˵������ĳ����ж�������������ֻ��ʦ��δ����\n"NOR);
                say(
CYN"������˵����������ʦ�Ӽø»��ѧ�գ�����һ��ù���ֻ��\n"NOR
CYN"            ��˵���������Ļ��浶������������ɸ�ʤһ�\n"NOR
CYN"            ��͵�빬�������̽һ����˭��ȴ�����֣�û�κ�\n"NOR
CYN"            Զ�����磬��������¡�����š�ǰ���ֱ����Ƿ���\n"NOR
CYN"            �ҵ���ʵ��ݣ�ֻ�ö��ʦ����������ӻ�������\n"NOR
CYN"            Ը�Ի��浶�׽����������������ȥ����ʦ��Ҫ��\n"NOR
CYN"            �ɡ������Ӵ���Ҫ�˼������ˡ�\n"NOR
                        );
                say(HIC"������һҾ��ȥ��\n"NOR);
                destruct(ob);
        }
        else
        {
                ::unconcious();
        }
}
