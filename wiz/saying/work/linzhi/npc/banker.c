//banker.c ��֥��Ǯׯ�ϰ塣
#include <ansi.h>
inherit NPC;
int ask_me();
void create()
{
        set_name("��Сƽ", ({ "lin xiaoping","lin"}) );
        set("title", "Ǯׯ�ϰ�");
        set("gender", "����" );
        set("age", 25);
        set("str", 53);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);

        set("long",
"��Сƽ�Ǹ��������൱˹�ĵ������ˣ�������ʱ��
����Щ�Ĳ����ɵ����ӣ���һ�����а������ڰ���
̾��������ȥ���ǰ����١�\n");

        set("combat_exp", 200000);
        set("attitude", "friendly");

        set("max_atman", 500);
        set("atman", 500);
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 20);
        set("max_mana", 500);
        set("mana", 500);

        set_skill("blade", 100);
        set_skill("unarmed",100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
//        set_skill("fire-blade", 100);
//        set_skill("dashouyin", 100);
//        set_skill("jimie-steps", 100);
//        set_skill("mizong-xinfa", 100);
//        map_skills("blade","fire-blade");
//        map_skills("unarmed","dashouyin");
//        map_skills("parry","fire-blade");
//        map_skills("dodge","jimie-steps");
//        map_skills("force","mizong-xinfa");
        set("inquiry",([
        "�����ϰ�":(:ask_me:),
]));
        setup();
        carry_object(WEAPON_DIR"blade")->wield();
        carry_object(ARMOR_DIR"cloth")->wear();
}
int ask_me()
{
        if ((int)this_player()->query_temp("mark/killed_huang"))
        message_vision(CYN"$N�����Ŀ���$nһ�ۣ�˵������ɽ���ģ���ˮ�����������ټ���\n"NOR,this_object(),this_player());      
        else
        {
        say(CYN"��Сƽ˵�������ϰ岻�ڡ�\n"NOR);
        this_player()->set_temp("mark/���ϰ�",1);
        }
        return 1;
}
void unconcious()
{
        object winner=query_temp("last_damage_from");
        object ob=this_object();
        if ((int)winner->query_temp("mark/���ϰ�"))
        {
                winner->remove_all_enemy();
                ob->remove_all_enemy();
                ob->set("kee",470);
                ob->set("force",2000);
                message_vision(CYN"��Сƽ��ս$N������æ����һ��ͣ��\n"NOR,winner);
                say(CYN"��Сƽ�ݺݵ�һЦ�������鷳�����Ҵ������ѵ�㣡\n"NOR);
                say(CYN"��Сƽ������̨��֪����ʲô������\n"NOR);
                message_vision(HIR"��Ȼ��ذ��ѿ���$N���˽�ȥ��\n"NOR,winner);
                winner->move("/wiz/saying/work/linzhi/bank_under");
                message("vision","��Ȼ���������һ���ˡ�\n",environment(winner),({winner}));
        }
        else
        {
                ::unconcious();
        }
}
//�뷨���£����fightӮ�˴��ˣ���this_player()->С�Թ�to�������
//Ӯ�˻�����this_player->set_temp("mark/���ϰ�",1)��С�Ƹ�������
//����Դ�Բ���������ʦ�����Ƿ������������еĺ��У���ȥ���Ϻ��У�
//���Եõ����浶�ĸ߼��鼮������ֻ��fightӮ����to�Թ���kill������
//С�Ƽ����kill�㣬����ɱ���������߼��鼮����һ����
