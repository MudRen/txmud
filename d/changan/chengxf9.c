// Room: chengxf9.c

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǳ���ة�ฮ�ĺ������������ǿ�����ˮĥʯ�ĵ��棬
ǽ�����ܣ���Щ���˵��ֻ���������λة�൹��һ�����ŵ��ˡ�
�����������������ǿ���������һ�����Լ����˻��Ǻܺ����Ѳ�
���Խ����ĵط�����������һ�����ң�����Ͷ��涼�����ң���
����������
LONG
	);

        set("exits", ([
  "south" : __DIR__"chengxf6",
  "north" : __DIR__"chengxf12",
  "east" : __DIR__"chengxf10",
  "west" : __DIR__"chengxf11",
]));
        setup();
        create_door("west", "ľ��", "east", DOOR_CLOSED,LOCKED,__DIR__"obj/cxf_key");
        // LOCKED  Ϊ�˷��䱻setupʱ������״̬�Ǳ����ŵģ�����ο� /include/room.h
        // Կ��������ļ���Ψһ���֡�����Կ������ı�д��
        // Կ�׵� name & id ��������д�����������ʶ��������
        // ��д can lock door ����ʱҪ���� key object ,���� load �˷���ᱨ��.
}