// condition.c
// Modified by Find.

#include <condition.h>
#include <origin.h>

mapping conditions;

nomask void update_condition()
{
	mixed err;
	int flag;
	object cnd_d;

	if( !mapp(conditions) || !sizeof(conditions) )
		return;

	foreach(string cnd, int cnt in conditions)
	{
		string cnd_file;

		cnd_d = find_object(cnd_file = CONDITION_D(cnd));
		if( !cnd_d )
		{
			if(file_size(cnd_file+".c") > 0)
			{
				err = catch(call_other(cnd_file, "???"));
				cnd_d = find_object(cnd_file);
			}

			if( err || !cnd_d )
			{
				log_file("condition.err",
					sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
						cnd_file, this_object(), err) );
				map_delete(conditions, cnd);
				continue;
			}
		}

		if( (flag = cnd_d->update_condition(this_object(), conditions[cnd])) == CND_NO_CHANGE )
			continue;

		if( (flag == CND_STOP) || (--conditions[cnd] <= 0) )
			map_delete(conditions, cnd);
	}
}

nomask void apply_condition(string cnd, mixed info)
{
	if( !mapp(conditions) )
		conditions = ([ cnd : info ]);
	else
		conditions[cnd] = info;
}

nomask varargs mixed query_condition(string cnd)
{
	if( !mapp(conditions)
	|| !sizeof(conditions) )
		return 0;

	if( stringp(cnd) )
	{
		if(!undefinedp(conditions[cnd]) )
			return conditions[cnd];
		else
			return 0;
	}
	return 0;
}

nomask varargs void clear_condition(string cnd)
{
	if(!cnd)
		conditions = ([]);
	else if(stringp(cnd) && mapp(conditions) && !undefinedp(conditions[cnd]))
		map_delete(conditions, cnd);
}
 