// xiaolu5.c

inherit ROOM;
void create()
{
        set("short","��·");
        set("long",@LONG                                   
�������ǻ�������������ˣ���·������Ҳ���ƽ����
���ˡ������Ǵ�ȳ������Ǵ���һ�ڹ��õ�ˮ��������һ����
С��Ժ����ǻ�����Ĵ峤���ʤ�ļ��ˡ�
LONG
        ); 
        
        set("exits",([ /* sizeof()==4 */
               "west":__DIR__"daguchang",
               "east" : __DIR__"shuijing",
               "north":__DIR__"cunzhang",
               
        ]) );

        set("outdoors", "huayin");
        setup();
        replace_program(ROOM);
}
