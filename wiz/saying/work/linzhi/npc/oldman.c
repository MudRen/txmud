//�����ү
#include <ansi.h>
inherit NPC;
int ask_forest(object me);
int ask_maple(object me);
void create()
{
       set_name("��������",({"old man","om"}));
       set("title",HIC"Ư������"NOR);
       set("age",75);
       set("gender", "����");

       set("long",@long
    һλ������ɣ�����ˣ��������Ͽ��Կ����������ܶ�Ŀ��ѡ�
���ϴ����·��ƺ������ʲ�̫��ϡ�
long
       );
       set("str", 20); 
       set("int", 40); 
       set("con", 10);
       set("dex", 30);
       set("per", 20);
      
       set("kee",200);
       set("max_kee",200);
       set("gin",300);
       set("max_gin",300);
       set("sen",100);
       set("max_sen",100);
       set_skill("unarmed",50);
       set_skill("dodge",50);
       set("combat_exp",10000);
       set("chat_chance",2);
       set("chat_msg",({
                CYN"��������˵���������ұܻ����ر�Ҳ�м�ʮ������Ҳ��֪������ô���ˡ�\n"NOR,
                CYN"��������˵�����벻���ҵ�����嵽�������ȻҪ���ˡ�\n"NOR,
                CYN"������������ãȻ�������૵�˵��ʲô��\n"NOR,
}));

       set("inquiry" ,([
       "����":"�����ҵ�����ӱ�ս�������쾳���Ⱳ�Ӷ��ز�ȥ�������Ǵ���ԭ������",
       "��ɭ��":(:ask_forest:),
       "������":(:ask_maple:),
       "all":"����������йء������֡�������ɭ�֡����������������顣",
]));
       setup();
       carry_object(__DIR__"obj/cloth.c")->wear();
       carry_object(__DIR__"obj/zang-xue.c")->wear();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if(!ob || environment(ob) != environment())
                return;

        switch(random(2))
        {
                case 0:
            say(CYN"�������˾�ϲ��˵����λ"+RANK_D->query_respect(ob)+"�Ǵ���ԭ������\n"NOR);
                        break;
                default:
                        {command("say �ʹ���ǧ�Ư����ʮ�ꡣ");
                         command(sprintf("sigh"));
                        }
        }
}
int ask_forest(object me)
{
        if ( this_player()->query_temp("marks/ɭ��") ) {
            say("����˵�������Ǹ�����������ϸ���ʼδ��ʦȥ��\n");
        }
        else {
                say(
"����˵������������һ����ѵ�ʱ��Ҳ�Ǵ��Ǹ���ɭ�ֹ����ġ�\n" 
"          ��Ϊ��֪���߷������Ǳ���������ö��죬����ż����\n"
"          ��������ӵ������ŵþȵģ������ҵ�����ȫ�����ˡ�\n"
                );
                command(sprintf("tell %s ��˵���滹��һ��ʥ������ʲôʥ���ػ��š�",me->query("id")));
                me->set_temp("mark/ɭ��", 1);
        }
        return 1;
}
int ask_maple(object me)
{
        if ( this_player()->query_temp("marks/������") ) {
            say("����˵�������Ǹ���������ȥ��ʱ��С�ĵ����\n");
        }
        else {
                say(
"����˵�����Ǹ�����������������˵���ֵ���һ���Ǵ����ʥ������˵\n" 
"          �Ǻܾ���ǰ��Ů���µľ��ӻ��ɵġ�����Ϊ���·��˵�ʥ����\n"
"          �ң�������������Թ�һ��ķ����֡�\n"
                );
                command(sprintf("tell %s �߹�(pass)������֮����һ�������أ���˵���ﻹ���˻��书��",this_player()->query("id")));
                this_player()->set_temp("mark/������", 1);
        }
        return 1;
}
