// huashan shuiyue.c ˮ�µ��� by pian 2000.8

#include <ansi.h>
inherit NPC;

string ask_for_zigong();

void create()
{
        set_name("ˮ�µ���", ({"shuiyue daozhang"}));
        set("title", MAG"�����"NOR);
        set("long",@LONG
ˮ�µ���ԭ�Ǵ��ڹ��е�һ����Ʒ̫
�࣬����������Ѿ���ʮ�����ˡ���
������̫��Ϊ���������ϣ�������
�ˡ����ǵ��˺��о������˵�ʿ��
LONG
        );

        set("gender", "����");

        set("attitude", "heroism");

        set("inquiry",([
                "�Թ�"  : (: ask_for_zigong :),
        ]));

        set("age", 73);
        set("kee", 1000);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("cps", 25);
        set("max_kee", 500);
        set("max_gin", 100);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 100);
        set("combat_exp", 15000);

        set("apply/attack",  30);
        set("apply/defense", 30);

        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);

        setup();
}

void init()
{
return;
        add_action("do_decide", "decide");
}

string ask_for_zigong()
{
        object me;

return 0;

        me = this_player();

        if( (string)me->query("gender")=="����" )
                return "����ͬ�����ˣ��αؿ�������ĵ���Ц��\n";

        if( (string)me->query("gender") == "Ů��" )
                return "�����ѳ��Ҷ��꣬Ůʩ�������ء�\n";
        if ((int)me->query_age() > 28 )
                return "�����̫���ˣ����в������㣬�װ��Թ������ף����ס�\n";

       me->set_temp("zigong", 1);
        return 
"  ��λ����...�Թ�֮�󲻿ɽ�飬û�к����������...���¾���(decide)�ˣ�\n";
}

int do_decide()
{
        if( !this_player()->query_temp("zigong") )
                return 0;

        message_vision(
             RED"$Nһҧ�����������£��ɵ����ϡ�\n\n"
                "$nȡ��һ������Ľ��У������м�����ɫС��ƿ��һ�Ѿ��Ƶ�С����\n\n"
                "$n����С��������$NһЦ��\n\n"
                "$N����һ��ë��"
                "$n���С���嵽$N����֮�䣬����һ�࣬����\n\n"
                "$N��ʱ�ҽ�һ�����˹�ȥ����\n\n"NOR,
                this_player(), this_object() );
        command("chat ������������������......");
        command("xixi");
        this_player()->set("gender","����");
        //this_player()->set("class", "eunach");
        this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
        this_player()->unconcious();
        return 1;
}

// ��Ǯ�����С�
int accept_object(object who,object ob)
{
           if ( !ob->value() ) {
                command("say ��л������!!");
                command("hehe");
                return 1;
        }
                                                                                                                                                                
        if( who->query_temp("zigong") )
          {
                if( ob->value() >= 50000 ) 
                {
                   who->delete_temp("zigong");
                   command("say �úã����ӿ������ˡ�");
                   return 1;
                   
                 } else 
                   command("think");
                   return 1;
          }else 
             command("say ��л�����׵ƻ�Ǯ�ˡ�");
        
        return 1;
}
