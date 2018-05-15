_prefix = meson.current_source_dir()

test('01_just_run', exe, args:['01.input'], workdir: _prefix)

compare = find_program('compare.sh')

# test('01_run_and_diff', compare, args:[exe.full_path(), _prefix+'/01.output', _prefix+'/01.input'], workdir: meson.current_build_dir())

# test('02_run_and_diff', compare, args:[exe.full_path(), _prefix+'/02.output', _prefix+'/02.input'], workdir: meson.current_build_dir())


_tests = ['01', '02']

foreach _t : _tests
  test(_t + '_run_and_diff',
       compare,
       args:[exe.full_path(),
             _prefix + '/' + _t + '.output',
             _prefix + '/' + _t + '.input'],
       workdir: meson.current_build_dir())
endforeach
