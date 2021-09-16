// Room: /d/hangzhou/hotel.c

#include <ansi.h>

inherit ROOM;

string m_id = "pao tang",m_name = "����";

void create()
{
	set("short", "��԰��¥");
	set("long", @LONG
����������һ�䷱���ľ�¥���棬���Ĵ�����ķ�������
��ʳ�ͣ�������������С��ææµµ�Ĵ����ڷ����͹˿�֮�䣬
�ƹ��Ҳæ����ʰ���ӡ�
LONG
	);

        set("night_long", @LONG
��԰��¥�к��ݵ�һ¥�������������Ѿ������ˣ����õ�û
����ɵ�ſ�ڹ�̨�ϡ�
LONG
        );

	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"minan03",
	"up" : __DIR__"hotell2",
	"east" : __DIR__"chufang",
]));

	set("valid_startroom",1);
	set(SAFE_ENV,1);

	set("objects",([
	__DIR__"npc/paotang" : 1,
]));
	setup();
	load_board("board_hangzhou");
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
