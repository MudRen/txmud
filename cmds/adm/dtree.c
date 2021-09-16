// dtree.c

inherit F_CLEAN_UP;

nomask int main(object me, string arg)
{
	string path,*files;
	int count;

	if(!arg || (arg == ""))
		return notify_fail("�޲�������\n");

	path = resolve_path(me->query("cwd"), arg);

	if(file_size(path) != -2)
		return notify_fail(path+" ����һ��Ŀ¼��\n");

	path += "/";
	files = get_dir(path);

	foreach(string file in files)
	{
		object ob = find_object(sprintf("%s%s",path,file));
		if(objectp(ob))
		{
			count++;
			destruct(ob);
		}
	}

	printf("����� %d �������\n",count);
	return 1;
}
