// xiuxiu.c

inherit NPC;

int is_hs_quest_xiuxiu() { return 1; }
protected object master;
protected void say_message();
protected int free;

object query_my_master() { return master; }

void create()
{
        set_name("����", ({ "xiu xiu" }) );
        set("gender", "Ů��");
        set("age", 17);
        set("long", "����һλƯ����ũ��Ů����\n");

        set("no_exp_gain",1);
        set("no_return_home",1);
        set("per",30);

        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
                (: say_message :),
        }) );

        set("max_kee",800);
        set("max_gin",600);
        set("max_sen",600);

        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

void been_free(object me)
{
        free = 1;

        if(!objectp(me))
                return;

        master = me;
        set_leader(me);
        command("say �����ʯ����(push)�����ǳ����ˣ����ܲ������һؼң��ء�����");
}

protected void say_message()
{
        object env;

        if(!objectp(env = environment()))
                return;

        if(!free)
                command("say ��λ��ʿ�Ⱦ��Ұ�����(za)�������ɣ���үү���ڼҵ������ء�����\n");

        else if(env->is_path2_dl())
        {
                if(env->query("exits/up"))
                        command("say ��λ��ʿ�ܲ������һؼ�ѽ���أ��ء�����");
                else
                        command("say �����ʯ����(push)�����ǳ����ˣ��Ⱦ��Ұɡ�����");
        }
}

