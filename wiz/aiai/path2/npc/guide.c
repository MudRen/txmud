// guide.c

#include <ansi.h>

inherit NPC;

string *random_name1 = ({
        "����",
        "����",
        "����",
        "����",
        "����",
        "����",
        "�ƹ�",
        "����",
        "��ɼ",
});

string *random_name2 = ({
        "����",
        "����",
        "·��",
        "������",
        "������",
        "����",
        "���ϴ�",
        "������",
        "����",
});

//protected string maze="/wiz/aiai/path2/midao";
protected string maze="/d/path2/midao";

string ask_me(object who);

protected void dest_me();

void create()
{
        int i;

        i=random(sizeof(random_name2));
        set_name(HIG+random_name1[random(sizeof(random_name1))]+
                random_name2[i]+NOR, 
                ({ "guide" }) );
                

        set("gender", "����" );

        set("age", random(30)+20);
        set("str", 20);
        set("cor", 30);
        set("int", 20);
        set("per", 20);
        set("con", 20);
        set("kar", 20);

        set("no_kill",1);

        set("long",@LONG
����һ���Ĵ��ε����ˣ���ʱ��������������
�������ˣ����æ���߿���
LONG );

        set("combat_exp", 100000);

        set("chat_chance", 5);
        set("chat_msg", ({
            (: random_move :)
        }) );

        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 60);

        set("inquiry", ([
                "����" : (: ask_me :),
                "xiuxiu" : (: ask_me :),
]) );

        setup();
                carry_object(ARMOR_DIR"cloth")->wear();
}

void init()
{
        if(find_call_out("dest_me") == -1)
                call_out("dest_me",60*6);
}

string ask_me(object who)
{
        object ob=this_object();
    object room,enter,me = this_player();
        object xin;

        if ( who->query("quest/huashan_quest/name")!="����չ���ܵ��ټ�" ||
                 !who->query("quest/huashan_quest/search") )
                 return 0;

        // �͵��ص���
        room = find_object(maze);
        if(!room)
                room = load_object(maze);
        if(!room)
                return "��ɽ��������������ִ���������ʦ���档\n";

        if(!objectp(enter = room->init_dilao(me)))
                return "��ɽ��������������ִ���������ʦ���档\n";

        tell_room(this_object(),me->name()+"����"+ob->name()+"һ�����ˡ�\n",({me}));
        me->move(enter);

                if ( objectp(xin=present("shouxin", me)) &&
                        xin->query("for_xiuxiu") )
                        destruct(xin);

        write(CYN+ob->name()+"˵�������Ƕ���������������İɣ�С����͸�����·��\n\n"
        +NOR"�����"+ob->name()+"������һ�����εĵط���\n");

        call_out("dest_me", 3);

        return "...";

}

protected void dest_me()
{
        if(environment())
            tell_object(environment(),this_object()->name()+"����ææ���뿪�ˡ�\n");
        destruct(this_object());
}



