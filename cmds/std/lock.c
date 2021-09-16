// lock.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
	string *dirs, dir;
	int i;

	if( !arg ) return notify_fail("��Ҫ��ʲô���ϣ�\n");

	doors = environment(me)->query_doors();
	if( mapp(doors) ) {
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 ) {
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("��Ҫ��ʲô���ϣ�\n");
	
		if( environment(me)->lock_door(me,dir) ) {
			message_vision("$N��" + doors[dir]["name"] + "�ϵ��������ˡ�\n", me);
			return 1;
		}
	}

	return 0;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : lock <door> �� <����>
 
���ָ�������������ϵ�������.
 
HELP
    );
    return 1;
}
