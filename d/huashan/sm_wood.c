// /d/huashan/sm_wood.c

inherit ROOM;

void create()
{
        set("short", "С����");
        set("long", @LONG
������һ��ï�ܵ�С���֡�����ɢ���Ź����ζ�������ֿ�
��������ɭ������ֱ��Ƥ���������ż�����������������
������������������������û����������о���Щ�Ļš�����
����������ʯ·��������һ��С���֣������ǲ���ȡ�
LONG
        );
        
        set("exits", ([
                "southwest" : __DIR__"sroad2",
                "east" : __DIR__"jindi_gate",
        ]));

        set("outdoors","huashan");

        setup();
}


