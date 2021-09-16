// old_beggar.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����ؤ", ({ "old beggar" }) );
        set("gender", "����" );
        set("class", "gaibang");
        set("age", 60);
        set("attitude","peaceful");
        set("long", "һ��������˪֮ɫ������ؤ�������ӽ����֡�\n");
        set("combat_exp", 20000);
        set("str", 25);
        set("max_force", 100);
        set("force", 100);
        set("is_beggar",1);
        set("chat_chance", 15);
        set("chat_msg", ({
                CYN"����ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ���Ǯ�ɡ�\n"NOR,
                CYN"����ؤ������ش��˸���Ƿ��\n"NOR,
                CYN"����ؤ����׽ס�����ϵ�ʭ�ӣ��������������û�����⣬ȫ�����Ǹ�ҧ���ˡ� \n"NOR,
                (: random_move :)
        }) );

        setup();

        if(random(2))
                carry_object(BOOK_DIR"old_book");
        carry_object(ARMOR_DIR"cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + "��������һ�����кñ��ģ�");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
        return 0;
}

