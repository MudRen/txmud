// snake_dan_dealer.c

#include <ansi.h>

inherit NPC;

string ask_job();
string ask_quit();

void create()
{
        set_name("�ߵ�����", ({ "snake_dan dealer" }) );
        set("gender", "����" );
        set("age", 45);
        set("attitude","peaceful");
        set("long", "����һ���ߵ����ӣ�ר�������ߵ���ҩ������ȥ��\n");
        set("combat_exp", 20000);
        set("per", 10);
        set("chat_chance", 2);
        set("chat_msg", ({
                CYN"�ߵ�����ߺ���ţ��չ������ߵ��������ߵ�����������\n"NOR,
        }) );

        set("inquiry",([
                "�ߵ�" : "�ԣ��Ҿ������ߵ��ģ����ߵ����ܸ��ҡ�",
                "job" : (: ask_job :),
                "quit" : (: ask_quit:),
        ]));

        set(NO_KILL, 1);

        setup();

        carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_job()
{
        object me = this_player();
        object ob = this_object();

        if(me->query("quest/public/snake_dan", 1))
        {
                return "�㲻���Ѿ���Ӧ��ȥ���ߵ���ô���ҵ��˽����Ҿͺá�";
        }

        if(me->query("quest/public/snake_quit", 1))
        {
                return RANK_D->query_respect(me) +"��ЪЪ����Ҫ�ۻ������ӡ�";
        }

        else
        {
                if((int)me->query("combat_exp", 1) < 250000)
                {
                        me->set("quest/public/snake_dan", 1);
                        me->set("quest/public/snake_kill", 1);
                        return RANK_D->query_respect(me) +"����ҵ����ߵ��ͽ����ң��Ҳ��������ġ�";
                }

                else 
                {
                        me->delete("quest/public/snake_dan");
                        me->delete("quest/public/snake_kill");
                        return RANK_D->query_respect(me) +"�书��ǿ�������ͷ�������ͼ��Ĺ����أ�";
                }
        }
}

string ask_quit()
{
        object me = this_player();
        object ob = this_object();

        if(me->query("quest/public/snake_dan", 1))
        {
                me->delete("quest/public/snake_dan");
                me->delete("quest/public/snake_kill");
                me->set("quest/public/snake_quit", 1);
                call_out("enable", 10, me);
                return "�ðɣ�"+ RANK_D->query_respect(me) +"��ȥ��Ϣ��Ϣ�ɣ������������ҡ�";
        }
        else
        {
                call_out("enable", 10, me);
                return RANK_D->query_respect(me) +"����û����Ҫ������̸���˳�����";
        }
}

int accept_object(object me, object obj)
{
        if(me->query("quest/public/snake_dan", 1))
        {
                if(obj->query("id") == "mang_snake dan")
                {
                        me->delete("quest/public/snake_dan");
                        me->delete("quest/public/snake_kill");
                        command("say "+ RANK_D->query_respect(me) +"���ĺã����ߵ��������ˣ����ҩ������ȥ�ɡ�");
                        new(__DIR__"obj/snake_powder")->move(me);
                        tell_object(me, YEL"����ߵ���������õ���һС���ߵ��ۡ�\n"NOR);
                        me->add("combat_exp", 20);
                        me->add("potential", 20);
                        tell_object(me, YEL"������ ��ʮ ��ʵս������ ��ʮ ��Ǳ�ܡ�\n"NOR);
                        call_out("destroying", 1, obj);
                        return 1;
                }
        }

        else return 0;
}

void destroying(object obj)
{     
        if (!obj) return;
        else destruct(obj);
}

void enable(object me)
{
        me->delete("quest/public/snake_quit");
}
