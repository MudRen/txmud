// Room: /d/hangzhou/cutshop.c

#include <ansi.h>

inherit ROOM;

string m_id = "hua dajie",m_name = "�����";

void create()
{
        set("short", "���ǲ÷���");
        set("long", @LONG
����һ��СС�Ĳ÷����ӣ��������񰲽ֵĽֽǣ�����ֻ��
һ�ų������������һЩ��������֮��Ķ�����һλ����Ĵ�ɩ
��æǰæ����к����ˡ�
LONG
        );

        set("night_long", @LONG
�����������񰲽ֵĽֽ�һ��СС�Ĳ÷����ӣ������Ѿ���
���ˣ����ϰ廹��æ��������Ļ�ơ�
LONG
        );

        set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"minan03",
]));
        set("objects",([
		__DIR__"npc/caifeng_boss" : 1,
]));

        setup();
}

void open_close_door(string msg,object user)
{
        object ob = present(m_id,this_object());

        if(!msg || !user)
                return;
        if( msg == "begin_day")
        {
                if(ob)
                        tell_object(user,sprintf(CYN"%sЦӯӯ�Ķ���˵������ʼӪҵ�ˣ���%s����㿴����\n"NOR,
				m_name,RANK_D->query_respect(user) ));
                else
                        tell_object(user,sprintf(CYN "%s��ʼӪҵ�ˡ�\n"NOR,query("short")));
                return;
        }

        else if( msg == "begin_night")
        {
                if(ob)
                        tell_object(user,sprintf(CYN"%s˵������λ%s�Բ���С�̴����ˣ��������������ɡ�\n"NOR,
				m_name,RANK_D->query_respect(user)));
                else
                        tell_object(user,sprintf(CYN "%s�����ˡ�\n"NOR,query("short")));
                return;
        }
}
