
inherit ROOM;

void create()
{
        set("short", "��ã����·");
        set("long", @LONG
ɽ�������･�����ߣ���Χ�ľ�����Ũ�����������֡�Ũ����
��ˮ��������͸��������ѣ����������������ܡ��⡭��������
��ͨ�����õ�·������ͨ������֮�ţ�
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"palace_path3",
  "west" : __DIR__"palace_path1",
 // "east":__DIR__"famuchang",
]));
        set("outdoors", "palace");

        setup();
        replace_program(ROOM);
}

