// Room: chengxf11.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǳ���ة�ฮ�����ң�һ������ǽ�Ϲ���һ���Ž�����
��һ�����ù���ļ��ӣ�ռ��������ǽ���������һЩ�����Զ
�Ĺ��棬��������һЩة�������ù��Ŀ��ס�������ȴ��������
������Щ����������ʲô�����������Ǻ�����
LONG
	);

	set("exits", ([
		"east" : __DIR__"chengxf9",
]));
        setup();

        create_door("east", "ľ��", "west", DOOR_CLOSED,LOCKED,__DIR__"obj/cxf_key");
        // LOCKED  Ϊ�˷��䱻setupʱ������״̬�Ǳ����ŵģ�����ο� /include/room.h
        // Կ��������ļ���Ψһ���֡�����Կ������ı�д��
        // Կ�׵� name & id ��������д�����������ʶ��������
        // ��д can lock door ����ʱҪ���� key object ,���� load �˷���ᱨ��.
}